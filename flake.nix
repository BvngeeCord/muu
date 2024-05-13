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
            #inherit stdenv;
          }
          {
            name = "muu";

            hardeningDisable = [ "fortify" ];

            packages = with pkgs; [
              nlohmann_json
              imagemagick
              #(imagemagick.override { inherit stdenv; }) # errors

              # dep of material-color-utilities
              #(abseil-cpp.override { inherit stdenv; })
              # TODO: probably have to compile this ourselves?
              # https://github.com/abseil/abseil-cpp/blob/master/FAQ.md#what-is-abi-and-why-dont-you-recommend-using-a-pre-compiled-version-of-abseil
              abseil-cpp

              meson
              ninja
              clang-tools
              pkg-config
            ];
          };
    };
}
