#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Author: Margarida Madeira e Moura 
# Contacts: mmadeira@ualg.pt
# Revision: $Revision: 2 $
# Date: $Date: 2013/05/08 $

""" 
Caso de teste 
Arte ou engenho
(problema proposto para o TOPAS 2013)
"""

resultado = int(raw_input())
passo1 = resultado - 9
if ((passo1 % 2)==0):
    divide = 3
else:
    divide = 5

if ((passo1 % divide) == 0):
    adivinha = passo1 / divide
    print adivinha
else:
    print "Acho que te enganaste nas contas."



