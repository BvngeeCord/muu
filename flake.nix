{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default =
        let
          stdenv = pkgs.llvmPackages_17.libcxxStdenv;
        in
        pkgs.mkShell.override
          {
            # material-color-utilities needs to be compiled with clang (gcc throws some errors)
            inherit stdenv;
          }
          {
            name = "muu";

            hardeningDisable = [ "fortify" ];

            
            packages = with pkgs; [
              nlohmann_json
              imagemagick

              # needed by material-color-utilities
              (abseil-cpp.override { inherit stdenv; })

              meson
              ninja
              clang-tools
              pkg-config
            ];
          };
    };
}
