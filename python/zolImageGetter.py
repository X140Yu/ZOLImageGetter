#!/usr/bin/python

'''
功能：获取http://dcbbs.zol.com.cn/jingxuan/178/1.html页面的极其子页面的所有图片
使用：直接运行，最好把它放在一个单独的文件夹中
'''

import sys
import os
import urllib
import re

# 通过URL获得页面的HTML
def getPageHTML(URL):
    return urllib.urlopen(URL).read()

# 通过URL获取页面所有的子页面URL
def getUrlList(baseUrl):
    baseHtml = getPageHTML(baseUrl)
    reg = r'<p><a href="(.*?\.html)" target='
    regURL = re.compile(reg)
    URLList = re.findall(regURL, baseHtml)
    return URLList

# 通过子页面的HTML，下载图片
def getImageUsingHTML(HTML, pageNum, dirNum):
     reg = r'\.jpg" src="(.*?\.jpg)" data-picid='
     imgre = re.compile(reg)
     imglist = re.findall(imgre, HTML)
     x = 1
     for i in imglist:
         fileName = './%s/%s/%s.jpg' % (pageNum, dirNum, x)
         urllib.urlretrieve(i, fileName)
         x += 1

# 通过页面的所有子链接，获取图片
def getImageUsingUrlList(urlList, pageNum):
    dirNum = 1
    for sonUrl in urlList:
        pageHTML = getPageHTML(sonUrl)
        os.makedirs('./%s/%s' % (pageNum, dirNum))
        getImageUsingHTML(pageHTML, pageNum, dirNum)
        dirNum += 1

# 遍历所有页面
def downloadAll(URL):
    for pageNum in range(1, 28):
        print 'Getting Page %s' % pageNum
        newURL = URL + '%s.html' % (pageNum)
        URLList = getUrlList(newURL)
        os.makedirs(str(pageNum))
        getImageUsingUrlList(URLList, pageNum)

downloadAll("http://dcbbs.zol.com.cn/jingxuan/178/")
