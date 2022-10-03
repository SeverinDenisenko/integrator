! Created by Severin on 23.09.2022.

function rectangle(f, a, b, n) result(res)
    implicit none
    real(8) :: f
    real(8) :: a
    real(8) :: b
    real(8) :: res, s, h
    integer(4) :: n, i

    s = 0

    h = (b - a) / n;
    do i = 1, n
        s = s + f(h * i);
    enddo
    res = s * h

end function rectangle
