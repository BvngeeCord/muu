{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        name = "muu";

        hardeningDisable = [ "fortify" ];

        packages = with pkgs; [
          nlohmann_json
          imagemagick_light
          # Note (might become significant later):
          # https://github.com/abseil/abseil-cpp/blob/master/FAQ.md#what-is-abi-and-why-dont-you-recommend-using-a-pre-compiled-version-of-abseil
          (abseil-cpp.override {
            cxxStandard = "20"; # not sure if this is necessary
          })

          meson
          ninja
          clang-tools
          pkg-config
        ];
      };
    };
}
