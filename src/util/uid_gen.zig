const Self = @This();

scope_uid: usize = 0,

pub fn init() Self {
    return .{ .scope_uid = 0 };
}

pub fn uid(self: *@This()) usize {
    const retval = self.scope_uid;
    self.scope_uid += 1;
    return retval;
}
