#lang sicp

; map elements in l by proc
(define (map proc l)
  (if (null? l)
      nil
      (cons (proc (car l))
            (map proc (cdr l)))))

(define (scale-list l factor)
  (map (lambda (x) (* factor x))
       l))

(define (add-list l increment)
  (map (lambda (x) (+ x increment))
       l))

(scale-list (list 1 2 3 4) 10)
(add-list (list 1 2 3 4) 42)