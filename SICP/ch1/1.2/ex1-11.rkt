#lang sicp

(define (f n)
  (if (< n 3)
    n
    (+ (f (- n 1)) (* 2 (f (- n 2))) (* 3 (f (- n 3))))))

(f 0)
(f 1)
(f 2)
(f 3)
(f 4)
(f 5)
(f 6)
(f 7)
(f 8)
(f 9)
(f 10)

; To compute f(n) (n >= 3) in iteration:
; iterate n - 2 times
; initial value a=2 b=1 c=0
; transform between iterations:
;    a <- a + 2 * b + 3 * c
;    b <- a
;    c <- b
(define (iter n a b c)
  (cond ((< n 3) a)
        (else (iter 
                (dec n) 
                (+ a (* 2 b) (* 3 c))
                a
                b))))

(define (f-iter n)
  (if (< n 3) n (iter n 2 1 0)))

(f-iter 0)
(f-iter 1)
(f-iter 2)
(f-iter 3)
(f-iter 4)
(f-iter 5)
(f-iter 6)
(f-iter 7)
(f-iter 8)
(f-iter 9)
(f-iter 10)
