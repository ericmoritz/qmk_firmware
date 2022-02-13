{
  inputs = {
    nixpkgs = { url = "github:nixos/nixpkgs/nixpkgs-unstable"; };

    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.nixpkgs.follows = "nixpkgs";
    };

    poetry2nix = {
      url = "github:nix-community/poetry2nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { nixpkgs, flake-utils, poetry2nix, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };

        # Builds the python env based on nix/pyproject.toml and
        # nix/poetry.lock Use the "poetry update --lock", "poetry add
        # --lock" etc. in the nix folder to adjust the contents of those
        # files if the requirements*.txt files change
        pythonEnv = pkgs.poetry2nix.mkPoetryEnv {
          projectDir = ./nix;
        };
      in
      with pkgs;
      let
        avrlibc = pkgsCross.avr.libcCross;

        avr_incflags = [
          "-isystem ${avrlibc}/avr/include"
          "-B${avrlibc}/avr/lib/avr5"
          "-L${avrlibc}/avr/lib/avr5"
          "-B${avrlibc}/avr/lib/avr35"
          "-L${avrlibc}/avr/lib/avr35"
          "-B${avrlibc}/avr/lib/avr51"
          "-L${avrlibc}/avr/lib/avr51"
        ];
      in
      {
        devShell =
          let
            # I don't know what these were but they were defaulting to
            # true. I am just trying to get this to work
            avr = true;
            arm = true;
            teensy = true;
          in
          mkShell
            {
              name = "qmk-firmware";

              buildInputs = [ clang-tools dfu-programmer dfu-util diffutils git pythonEnv poetry niv ]
                ++ lib.optional avr [
                pkgsCross.avr.buildPackages.binutils
                pkgsCross.avr.buildPackages.gcc8
                avrlibc
                avrdude
              ]
                ++ lib.optional arm [ gcc-arm-embedded ]
                ++ lib.optional teensy [ teensy-loader-cli ];

              AVR_CFLAGS = lib.optional avr avr_incflags;
              AVR_ASFLAGS = lib.optional avr avr_incflags;
              shellHook = ''
                # Prevent the avr-gcc wrapper from picking up host GCC flags
                # like -iframework, which is problematic on Darwin
                unset NIX_CFLAGS_COMPILE_FOR_TARGET
              '';
            };
      });
}
