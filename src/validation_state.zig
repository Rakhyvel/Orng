/// Represents different validation states of an object.
pub fn Validation_State(comptime T: type) type {
    return union(enum) {
        /// Validation has not been done, undetermined state.
        unvalidated,

        /// Validation is currently in progress, undetermined state.
        validating,

        /// Validation completed successfully.
        valid: struct {
            /// The valid form
            valid_form: T,
        },

        /// Validation completed unsuccessfully.
        invalid,
    };
}
