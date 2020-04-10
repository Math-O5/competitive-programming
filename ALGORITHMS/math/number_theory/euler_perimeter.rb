#Training ruby code
#Math-05
#Special Pythagorean triplet

#A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

#a^2 + b^2 = c^2
#For example, 32 + 42 = 9 + 16 = 25 = 52.

#There exists exactly one Pythagorean triplet for which a + b + c = 1000.
#Find the product abc.

class Polygon
    
    def perimeter (n)
        for i in 1 .. n
            for j in i .. n
                k = n - i - j;
                if ((i*i) + (j*j) == k*k)
                    puts "#{i} #{j} #{k}"
                end    
            end
        end
    end

end


tri = Polygon.new
tri.perimeter (1000)