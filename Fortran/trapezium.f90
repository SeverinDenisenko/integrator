! Created by Severin on 23.09.2022.

function trapezium(f, a, b, n) result(res)
    implicit none
    real(8) :: f
    real(8) :: a
    real(8) :: b
    real(8) :: res, h, s
    integer(4) :: n, i

    res = 0
    s = 0

    h = (b - a) / n;

    do i = 2, n - 1
        s = s + f(h * i);
    enddo

    res = ((f(b) + f(a)) / 2 + s) * h

end function trapezium
