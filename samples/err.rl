action cmd_err {
    printf( "command error\n" );
    fhold; fgoto line;
}
action from_err {
    printf( "from error\n" );
    fhold; fgoto line;
}
action to_err {
    printf( "to error\n" );
    fhold; fgoto line;
}

line := [^\n]* ’\n’ @{ fgoto main; };

main := (
    (
        ’from’ @err(cmd_err)
            ( ws+ address ws+ date ’\n’ ) $err(from_err) |
        ’to’ @err(cmd_err)
            ( ws+ address ’\n’ ) $err(to_err)
    )
)*;
