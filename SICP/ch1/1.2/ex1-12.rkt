#lang sicp


(define (pascal row col)
  (cond ((or (> col row) (< col 1) (< row 1)) -1)
        ((or (= col row) (= col 1)) 1)
        (else (+ (pascal (dec row) (dec col)) (pascal (dec row) col)))))

(pascal 1 1)
(pascal 1 2)
(pascal 1 3)
(pascal 1 4)

(pascal 2 1)
(pascal 2 2)
(pascal 2 3)
(pascal 2 4)

(pascal 3 1)
(pascal 3 2)
(pascal 3 3)
(pascal 3 4)

(pascal 4 1)
(pascal 4 2)
(pascal 4 3)
(pascal 4 4)

(pascal 5 1)
(pascal 5 2)
(pascal 5 3)
(pascal 5 4)
(pascal 5 5)