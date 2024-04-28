#lang sicp

(define (cont-frac n d k)
  (define (tail-k i)
    (if (= i k)
        (/ (n k) (d k))
        (/ (n i) (+ (d i) (tail-k (+ i 1))))))
  (tail-k 1))

(define (one-over-phi k)
  (cont-frac (lambda (i) 1.0)
             (lambda (i) 1.0)
             k))
            
(display "recursive")
(newline)
(one-over-phi 10)
(one-over-phi 20)
(one-over-phi 50)

(define (cont-frac-iter n d k)
  (define (iter k res)
    (if (< k 1)
      res
      (iter (- k 1) (/ (n k) (+ (d k) res)))))
  (iter k 0.0))

(define (one-over-phi-iter k)
  (cont-frac-iter (lambda (i) 1.0)
             (lambda (i) 1.0)
             k))

(display "iterative")
(newline)
(one-over-phi-iter 10)
(one-over-phi-iter 20)
(one-over-phi-iter 50)