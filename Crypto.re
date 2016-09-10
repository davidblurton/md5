open Cryptokit;

let module Crypto = {
  let md5 contents =>
    contents
    |> hash_channel (Hash.md5 ())
    |> transform_string (Hexa.encode ())
}
