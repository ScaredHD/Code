#lang sicp

(define (square-tree tree)
  (cond ((null? tree) nil)
        ((not (pair? tree)) (* tree tree))
        (else (cons (square-tree (car tree)) (square-tree (cdr tree))))))

(define (map proc l)
  (if (null? l)
      nil
      (cons (proc (car l))
            (map proc (cdr l)))))

(define (square-tree-map tree)
  (map (lambda (x)
         (if (pair? x)
             (square-tree-map x)
             (* x x)))
       tree))

(define l (list 1
                (list 2 (list 3 4) 5)
                (list 6 7)))

(square-tree l)
(square-tree-map l)