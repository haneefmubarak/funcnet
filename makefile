all: build/funcnet build/README.build.md
	less build/README.build.md

build/funcnet: build
	gcc funcnet.c -o build/funcnet

build/README.build.md:
	cp README.md build/README.build.md -v

clean: build
	rm -rvf build

build:
	mkdir -pv build
