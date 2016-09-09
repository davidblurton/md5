build:
	ocamlfind ocamlc -g -thread -package core -package Cryptokit -pp refmt -linkpkg -o md5.native -impl md5.re
