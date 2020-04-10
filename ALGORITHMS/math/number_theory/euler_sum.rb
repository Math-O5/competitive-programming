#Training ruby code
#Math-05

#Sum square difference

#The sum of the squares of the first ten natural numbers is,
#12 + 22 + ... + 102 = 385

#The square of the sum of the first ten natural numbers is,
#(1 + 2 + ... + 10)2 = 552 = 3025

#Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
#Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

class Euler 
    
    def summation (n)
        @sum = 0
        @sumtwo = 0
        for i in  0 .. n do
            @sum += i
            @sumtwo += i * i
        end
        @sum *= @sum
        
        puts "The sum of the n first squares is #{@sumtwo}"
        puts "The square of the sum with the n is #{@sum}"
    end
 
end


primeiros_sem_numeros = Euler.new
primeiros_sem_numeros.summation(100)
