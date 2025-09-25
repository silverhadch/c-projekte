{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [

    # --- Compilers ---
    pkgs.gcc
    pkgs.clang
    pkgs.gnumake
    pkgs.ninja

    # --- Build Tools ---
    pkgs.cmake
    pkgs.autoconf
    pkgs.automake
    pkgs.pkg-config
    pkgs.bison
    pkgs.flex
    pkgs.git
    pkgs.gitAndTools.git-lfs

    # --- Debug & Profiling ---
    pkgs.gdb
    pkgs.valgrind
    pkgs.strace
    pkgs.ltrace
    pkgs.perf
    pkgs.lcov

    # --- Libraries / Dev Headers ---
    pkgs.zlib
    pkgs.openssl
    pkgs.libffi
    pkgs.libuuid
    pkgs.libcap
    pkgs.sqlite
    pkgs.bzip2
    pkgs.xz
    pkgs.libxml2
    pkgs.libxslt
    pkgs.ncurses
    pkgs.readline
    pkgs.linuxHeaders
    pkgs.btrfs-progs
    pkgs.e2fsprogs
    pkgs.util-linux

    # --- Qt/Kirigami (GUI dev) ---
    pkgs.qt6.full
    pkgs.kdePackages.kirigami
    pkgs.kdePackages.kirigami-addons
    pkgs.kdePackages.qtbase
    pkgs.extra-cmake-modules

    # --- Dev Utilities ---
    pkgs.cscope
    pkgs.ctags
    pkgs.ripgrep
    pkgs.fzf
    pkgs.tldr
    pkgs.shellcheck
    pkgs.difftastic
    pkgs.clang-tools
    pkgs.lsof
    pkgs.htop
  ];

  shellHook = ''
    echo "Welcome to your giant C/Kirigami dev shell!"

    # Library paths
    export LD_LIBRARY_PATH=${pkgs.zlib}/lib:${pkgs.openssl}/lib:$LD_LIBRARY_PATH
    export PKG_CONFIG_PATH=${pkgs.zlib}/lib/pkgconfig:${pkgs.openssl}/lib/pkgconfig:$PKG_CONFIG_PATH
  '';
}

