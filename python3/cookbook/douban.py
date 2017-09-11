#!/usr/bin/env python3

import requests,re,json,html2text,sys,time
import os
from bs4 import BeautifulSoup
import time
from urllib.request import urlretrieve

url="https://www.douban.com/group/haixiuzu/"
#url="http://127.0.0.1:8080/"
dir_on_disk = r'/tmp/douban'
from_page = 0
end_page = 30

if not os.path.exists(dir_on_disk):
    os.makedirs(dir_on_disk)

headers = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.103 Safari/537.36'
}

session = requests.Session()
session.get(url, headers=headers)


def getTopicList():
    for x in range(from_page, end_page):
        page = x * 25 + 1;
        start_url = url + "discussion?start=" + str(page)
        print("========== %s ==========" % start_url)
        response = session.get(start_url, headers=headers)
        soup = BeautifulSoup(response.text, "html.parser")
        tdList = soup.find_all("td", class_='title')
        for td in tdList:
            href = td.a.get('href')
            getTopicContext(href)
        time.sleep(2)


def getTopicContext(topicUrl):
    url = session.get(topicUrl)
    soup = BeautifulSoup(url.text, "html.parser")
    topicDiv = soup.find_all("div", class_='topic-figure cc')
    for div in topicDiv:
        if len(div.contents) > 1:
            img = div.img
            saveImage(img.get("src"))


def saveImage(imgUrl):
    fileName = imgUrl[imgUrl.rfind("/")+1:]
    path = r"/tmp/douban/" + fileName
    print("retrieving %s" % imgUrl)
    urlretrieve(imgUrl, path)

if __name__=="__main__":
    getTopicList()
