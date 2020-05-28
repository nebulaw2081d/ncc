# Maintainer: Noji Camrax <eel52 [at] nebulacentre [dot] net>
pkgname=ncc
pkgver=1.0.0
pkgrel=1
pkgdesc="Simple clock, stopwatch, timer written in C."
arch=("any")
license=("GPL2")
depends=("glibc")
makedepends=("gcc")
provides=("ncc")
source=("https://nebulacentre.net/code/ncc.c")
md5sums=("91b15cbd6b18b4bc80572516203d9e31")
url="https://nebulacentre.net"

build() {
	gcc -o "$srcdir/ncc" "$srcdir/ncc.c"
}

package() {
	install -d "$pkgdir/usr/bin"
	cp "$srcdir/ncc" "$pkgdir/usr/bin"
}
