all:
	cargo build
	cp ./target/debug/rustcalls* ./target/
	g++ -g src/main.cpp -lrustcalls -L./target/debug -o ./target/cppcaller

run: all
	./target/cppcaller

clean:
	cargo clean
