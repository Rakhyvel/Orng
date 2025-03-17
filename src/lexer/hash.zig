//! This file is responsible for calculating the hash of a module, to track changes

const std = @import("std");

const Self = @This();

module_contents_hash: *u64,

pub fn init(module_contents_hash: *u64) Self {
    return Self{
        .module_contents_hash = module_contents_hash,
    };
}

pub fn run(self: *Self, contents: []const u8) error{}![]const u8 {
    self.module_contents_hash.* = std.hash.XxHash3.hash(0, contents);
    return contents;
}
