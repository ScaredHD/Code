#lang sicp

(define (make-mobile l r)
  (list l r))

(define (make-branch len structure)
  (list len structure))

; ===== a. ======

(define (left-branch mobile)
  (car mobile))

(define (right-branch mobile)
  (cadr mobile))

(define (branch-len branch)
  (car branch))

(define (branch-structure branch)
  (cadr branch))

; ====== b. ======
(define (leaf? branch)
  (not (pair? (branch-structure branch))))

(define (total-weight mobile)
  (if (not (pair? mobile))
      mobile
      (let ((lb (left-branch mobile))
            (rb (right-branch mobile)))
        (+ (if (leaf? lb)
               (branch-structure lb)
               (total-weight (branch-structure lb)))
           (if (leaf? rb)
               (branch-structure rb)
               (total-weight (branch-structure rb)))))))


(define x (make-mobile
           (make-branch 3 (make-mobile
                           (make-branch 4 6)
                           (make-branch 2 (make-mobile
                                           (make-branch 1 7)
                                           (make-branch 1 8)))))
           (make-branch 4 (make-mobile
                           (make-branch 1 (make-mobile
                                           (make-branch 2 9)
                                           (make-branch 2 10)))
                           (make-branch 5 11)))))


(total-weight x)

; ====== c. ======
(define (balanced? mobile)
  (let ((lb (left-branch mobile))
        (rb (right-branch mobile)))
    (and (if (leaf? lb)
             #t
             (balanced? (branch-structure lb)))
         (if (leaf? rb)
             #t
             (balanced? (branch-structure rb)))
         (= (* (branch-len lb) (total-weight (branch-structure lb)))
            (* (branch-len rb) (total-weight (branch-structure rb)))))))

(balanced? (make-mobile
            (make-branch 3 4)
            (make-branch 4 3)))

(balanced? (make-mobile
            (make-branch 6 3)
            (make-branch 3 (make-mobile
                            (make-branch 1 4)
                            (make-branch 2 2)))))

(balanced? x)

(balanced? (make-mobile
            (make-branch 1 4)
            (make-branch 2 3)))


; ====== d. ======
; definition of 'make-mobile' and 'make-branch' changed to:
;  (define (make-mobile left right) (cons left right))
;  (define (make-branch length structure) (cons length structure))

; only answer (a), that is the selectors need to change
; new selectors use 'car' and 'cdr' directly