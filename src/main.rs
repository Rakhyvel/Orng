// rust is over engineered and garbage trash but its the only non-toy imperative language that has sum types!
// absolutely fuck zig

use std::env;
use std::fs::File;
use std::io::prelude::*;
use std::path::Path;
use std::result::Result;
use std::error::Error;

fn main()->Result<(), Box<dyn Error>> {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        panic!("usage: cargo run <filename>");
    }

    // Open input file, read contents
    let mut file = File::open(&Path::new(&args[1]))?;
    let mut contents: String = String::new();
    file.read_to_string(&mut contents)?; // turn this into a list of tokens
    let tokens = read_in_tokens(&contents);

    println!("{}", contents);
    println!("{:?}", tokens);

    Ok(())
}

// Takes in a String, returns a Vector of slices into that string that represent tokens
fn read_in_tokens(contents: &String)->Vec<String> {
    let mut pre_tokens: Vec<String> = Vec::new();
    let mut token: String = String::from("");

    // Needs to ignore comments untoken-ly so that things like /// are still a comment
    // Needs to do strings and characters, and not comment those, and preserve their whitespace
    // Needs to be able to do 0x, 0o and 0b integers, as well as regular integers
    // Needs to be able to do decimals, but with just a single decimal point
    // Preserve whitespace for calculating indentation (perhaps add a new token after a newline token)
    // Accurately detect the token kind for each

    return pre_tokens;
}
