#lang racket


(define (check r1 c1 r2 c2)
  (if (= r1 r2)
      (= c1 c2)
      (cond ((= c1 c2) #f)
            ((= (abs (- r1 r2)) (abs (- c1 c2))) #f)
            (else #t))))

(define (valid-placement? placement len)
  (empty?
   (filter
    (lambda (b) (not b))
    (flatten
     (map
      (lambda (r1)
        (map
         (lambda (r2)
           (check r1 (list-ref placement (- r1 1)) r2 (list-ref placement (- r2 1))))
         (inclusive-range (+ r1 1) len)))
      (inclusive-range 1 len))))))


(define (places k n)
  (if (= k 0)
      (list null)
      (filter
       (lambda (p-appended)
         (valid-placement? p-appended k))
       (foldr append null
              (map (lambda (p)
                     (map (lambda (next)
                            (append p (list next)))
                          (inclusive-range 1 n)))
                   (places (- k 1) n))))))

(define solutions (places 8 8))

(length solutions)
solutions