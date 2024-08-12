#lang sicp

(define (append a b)
  (if (null? a)
      b
      (cons (car a) (append (cdr a) b))))

(define (parity n)
  (remainder n 2))

(define (same-parity a . rest)
  (define (filter l)
    (if (null? l)
        nil
        (append (if (= (parity (car l)) (parity a))
                    (list (car l))
                    nil)
                (filter (cdr l))))
    )
  (append (list a) (filter rest)))

(same-parity 1 2 3 4 5 6 7)
(same-parity 2 3 4 5 6 7)
