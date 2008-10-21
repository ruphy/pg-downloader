
54.times do |i|
system("wget -O - 'http://www.paginegialle.it/pgol/1-006644400/4-ottica%20lenti%20a%20contatto%20ed%20occhiali%20vendita%20al%20dettaglio/l-1/p-"+i.to_s+"?mr=100&rk=4' >> big-bad-file.html")
end



