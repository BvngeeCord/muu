{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/master";

  outputs = { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        name = "muu";
        packages = with pkgs; [
          nlohmann_json

          meson
          ninja
          clang-tools
          pkg-config
        ];
      };
    };
}
