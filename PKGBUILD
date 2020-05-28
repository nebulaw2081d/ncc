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
md5sums=("af3e96181b76683034c232304a7edf89")
url="https://nebulacentre.net"

build() {
	gcc -o "$srcdir/ncc" "$srcdir/ncc.c"
}

package() {
	install -d "$pkgdir/usr/bin"
	cp "$srcdir/ncc" "$pkgdir/usr/bin"
}
