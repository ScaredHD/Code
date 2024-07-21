#lang sicp

(define (square x) (* x x))

;; base^exp mod m
(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp) 
          (remainder 
            (square (expmod base (/ exp 2) m)) 
            m))
        (else 
          (remainder 
            (* base (expmod base (dec exp) m)) 
            m))))

(define (fermat-test n)
  (define (try-it a)
    (= (expmod a n n) a))
  (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) true)
        ((fermat-test n) (fast-prime? n (- times 1)))
        (else false)))
      

(define times 10)

(fast-prime? 2 times)
(fast-prime? 3 times)
(fast-prime? 4 times)
(fast-prime? 5 times)
(fast-prime? 6 times)
(fast-prime? 7 times)
(fast-prime? 8 times)
(fast-prime? 9 times)
(fast-prime? 10 times)
(fast-prime? 11 times)
(fast-prime? 12 times)
(fast-prime? 13 times)
(fast-prime? 14 times)
(fast-prime? 15 times)
(fast-prime? 16 times)
(fast-prime? 17 times)
(fast-prime? 18 times)
(fast-prime? 19 times)
(fast-prime? 20 times)
(fast-prime? 21 times)
(fast-prime? 22 times)
(fast-prime? 23 times)
(fast-prime? 24 times)
(fast-prime? 25 times)
