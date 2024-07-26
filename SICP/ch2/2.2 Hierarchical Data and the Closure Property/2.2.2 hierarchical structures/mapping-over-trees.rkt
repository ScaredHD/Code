#lang sicp

(define (scale-tree tree factor)
  (cond ((null? tree) nil)
        ((not (pair? tree)) (* factor tree))
        (else (cons (scale-tree (car tree) factor)
                    (scale-tree (cdr tree) factor)))))

(define l (list 1 (list 2 (list 3 4) 5) (list 6 7)))

(define (map proc l)
  (if (null? l)
      nil
      (cons (proc (car l))
            (map proc (cdr l)))))

(define (scale-tree-2 tree factor)
  (map (lambda (x)
         (if (pair? x)
             (scale-tree-2 x factor)
             (* x factor)))
       tree))

(scale-tree l 10)
(scale-tree-2 l 10)