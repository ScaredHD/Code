#lang sicp

(#%require (only "../../ch2_common.rkt" accumulate))
(#%require (only sicp nil))

(define fold-right accumulate)

(define (fold-left op init seq)
  (define (iter result rest)
    (if (null? rest)
        result
        (iter (op result (car rest))
              (cdr rest))))
  (iter init seq))

(fold-right / 1 (list 1 2 3))  ; 1 / (2 / (3 / 1))
(fold-left / 1 (list 1 2 3))  ; ((1 / 1) / 2) / 3
(fold-right list nil (list 1 2 3))
(fold-left list nil (list 1 2 3))

; For fold-left and fold-right (with initial values) to produce the same result,
;   operation must be associative and commutative.
; For fold with no initial values, associativity alone
;   guarantees the equivalence of fold-left and fold-right.

