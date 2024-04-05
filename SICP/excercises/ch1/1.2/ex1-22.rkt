#lang sicp

(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))
      
(define (divides? a b) (= (remainder b a) 0))

(define (square x) (* x x))

(define (prime? n) (= n (smallest-divisor n)))

(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))

(define (start-prime-test n start-time)
  (if (prime? n)
      (report-time (- (runtime) start-time))))

(define (report-time elapsed-time)
  (display " *** ")
  (display elapsed-time))

(define (search-for-primes start count)
  (define (make-sure-odd n)
    (if (odd? n) n (+ n 1)))
  (timed-prime-test (make-sure-odd start))
  (if (> count 0) (search-for-primes (+ 2 (make-sure-odd start)) (- count 1))))

(search-for-primes 10000000 20)
(search-for-primes 100000000 20)
(search-for-primes 1000000000 20)