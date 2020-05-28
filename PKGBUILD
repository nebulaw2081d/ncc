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
md5sums=("2189b9fdcf91b21cc3753f64a5553d1d")
url="https://nebulacentre.net"

build() {
	gcc -o "$srcdir/ncc" "$srcdir/ncc.c"
}

package() {
	install -d "$pkgdir/usr/bin"
	cp "$srcdir/ncc" "$pkgdir/usr/bin"
}
