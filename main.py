#!/usr/bin/python
import web
import getdata

render = web.template.render('templates/')
urls = ('/', 'index')

com = getdata.talk()
paref = 15000

p1reslist = []
p2reslist = []

class index:

    def GET(self):
        co = com.getstrval("A")
        liste = getdata.listes()
        p1res = liste.make(13,"B",p1reslist)
        p2res = liste.make(13,"C",p2reslist)
        pos = com.getintval("D")
        diff = com.getstrval("E")
        
        return render.index(paref, co, diff, p1res, p2res, pos)
        
if __name__ == "__main__": 
    app = web.application(urls, globals())
    app.run()      
