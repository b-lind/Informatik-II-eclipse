proc handle_eof { expect_out_buffer expected_output test_name printed_output} {

    set lines [split $expect_out_buffer \n]
    set input [lindex $lines 0]
    set printed_output [lindex $lines $printed_output]
    fail "$test_name:
\tPrograms output doesn't match the expected output:
\t\tInput: $input
\t\tCorrect Output: $expected_output
\t\tPrinted Output: $printed_output"

}
