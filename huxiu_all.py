from urllib.request import urlopen
from bs4 import BeautifulSoup
import os

#lalala
def getArticle(url):
	try:
		html = urlopen(url)
		bsobj = BeautifulSoup(html.read(), "html.parser")
		f = open("F:\Python\huxiuArticle\%s.txt" % bsobj.h1.get_text(), "w", encoding='utf-8')
		f.write(bsobj.h1.get_text() + '\n')
		article = bsobj.find("div", {"id" : "article_content"}).findAll("p")
		for line in article:
			f.write(line.get_text() + '\n')
		f.close()
	except Exception as e:
		print(e)
	

def getURL():
	for x in range(170000,180000):
		getArticle("https://www.huxiu.com/article/" + str(x) + ".html")

getURL()