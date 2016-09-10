open Core.Std;
open Crypto;

let get_inchan = fun
  | "-" => In_channel.stdin
  | filename => In_channel.create binary::true filename;

let do_hash filename =>
  fun () =>
    get_inchan filename
    |> Crypto.md5
    |> print_endline;

let command =
  Command.basic
    summary:: "Generate an MD5 hash of the input data"
    Command.Spec.(empty +> anon (maybe_with_default "-" ("filename" %: file)))
    do_hash;

Command.run
  version:: "0.1"
  command;
