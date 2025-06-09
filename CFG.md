Terminals are upper-case while non-terminals only have the first character encapsulated

```
Stmt  ->  ExprSEMI
       |  AsgnSEMI

Asgn  ->  NAME = NUM

Expr  ->  (Expr)
       |  NAME Op Expr
       |  NUM Op Expr
       |  NUM

Definition of terminals:
SEMI: Semicolon character ';'
NAME: An identifier
NUM: Interger literal
```
