# coding: utf-8
"[Luke:] I can’t believe it. [Yoda:] That is why you fail.".include? 'Yoda'

"Ruby is a beautiful language".start_with? "Ruby"
"I can't work with any other language but Ruby".end_with? 'Ruby'

"I am a Rubyist".index 'R'

s = "hello " << "Shanghai"

"I should look into your problem when I get time".sub('I','We')
"I should look into your problem when I get time".gsub('I','We')
'RubyMonk'.gsub(/[aeiou]/, '1')

'RubyMonk Is Pretty Brilliant'.match(/.* Pre/) # #<MatchData "RUbyMonk Is Pre">
                                               # the method just returns the first match
                                               # rather than all the matches
