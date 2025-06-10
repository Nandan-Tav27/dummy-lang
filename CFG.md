Terminals:
```
NAME
NUM
ASGNOP( =)
ADDOP( + )
SUBOP( - )
MULTOP( * )
DIVOP( / )
LPAREN( '(' )    
RPAREN( ')' )
SEMI( ; )
```

Grammar:
```
Statement   → Assignment SEMI
            | Expression SEMI        // chosen when look-ahead after NAME ≠ '='

Assignment  → NAME ASGNOP Expression

Expression  → Term Expression′

Expression′ → ADDOP Term Expression′
            | SUBOP Term Expression′
            | ε

Term        → Factor Term′

Term′       → MULTOP Factor Term′
            | DIVOP Factor Term′
            | ε

Factor      → NAME
            | NUM
            | LPAREN Expression RPAREN
```

