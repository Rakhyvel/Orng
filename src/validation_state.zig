/// Represents different validation states of an object.
///
/// Validation can be represented by this DFA:
///
///   unvalidated    - Object has not been validated, yet
///        |
///        |
///        |
///    validating    - Object is in the process of being validated
///        |
///       / \
///      /   \
///   valid   \      - Object has been validated, found to be valid
///            \
///          invalid - Object has been validated, found to be invalid
///
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
