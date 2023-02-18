pkgname=dstruct
pkgver=1
pkgrel=1
epoc=
pkgdesc="A type agnostic data structure library"
arch=(x86_64)
url="https://github.com/bacal/dstruct"
license=('GPLv3')
groups=()
depends=(cmake
	gtest)
makedepends=()
checkdepends=()
optdepends=()
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=()








noextract=()
validpgpkeys=()

prepare() {
  mkdir -p build

  cd build
}

build() {
  cmake .. -G "Unix Makefiles"\
	-DCMAKE_INSTALL_PREFIX="/usr"
  make
}

check(){
  make test
}


package() {
  make DESTDIR="${pkgdir}" install
}
