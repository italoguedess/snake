{ pkgs ? import (fetchTarball "https://github.com/NixOS/nixpkgs/archive/c7a18f89ef1dc423f57f3de9bd5d9355550a5d15.tar.gz") {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    cmake
    gcc
    ninja
    sfml
  ];

}
