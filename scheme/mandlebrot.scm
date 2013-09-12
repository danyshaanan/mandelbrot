(define w 640)
(define h 640)
(define x -0.7)
(define y 0)
(define zoom 200)
(define radius  (expt 2 3))
(define maxIterations 41)

(define (get-point val len z axis) 
		(+ axis (/ (- val (/ len 2)) z)))

(define areal (map (lambda (p) (list p  (get-point p w zoom x))) (range w)))
(define bimag (map (lambda (p) (list p  (get-point p h zoom y))) (range h)))

(define (create-line-list real imag-list)
	(map (lambda (imag) (list (car real) (car imag) (make-rectangular (cadr real) (cadr imag)))) imag-list))
	
(define (create-matrix real-list imag-list)
	(map (lambda (real) (create-line-list real imag-list)) real-list))
	
(define mat (create-matrix areal bimag))

(define (color-pixel z iter)
	(+ 128 (* 128 (sin (- iter (/ (log (magnitude z)) (log radius))))))) 

(define (mandlebrot-iteration z)
		(define (mandle-step z cz cntr)
			(if (and (< cntr maxIterations) (< (magnitude z) radius))
				(mandle-step (+ (* z z) cz) cz (+ 1 cntr))
				(if (< cntr maxIterations)
					(list z (color-pixel z cntr))
					(list z 0))))
		(mandle-step z z 0))

(define (mandlebrot-row row)
	(map (lambda (item) (list (car item) (cadr item) (mandlebrot-iteration (caddr item)))) row))

(define (mandlebrot-matrix matrix) (map mandlebrot-row matrix))

(define mandlebrot-set (mandlebrot-matrix mat))