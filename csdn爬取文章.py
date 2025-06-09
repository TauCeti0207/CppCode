'''
Descripttion: 
Author: tauceti0207
version: 
Date: 2025-05-05 22:10:08
LastEditors: tauceti0207
LastEditTime: 2025-06-08 11:02:48
'''
import requests
import parsel
import tomd
import os
import re

# 对一篇文章的爬取
def spider_csdn(title_url):  # 目标文章的链接
    head = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.105 Safari/537.36 Edg/84.0.522.52",
        "Referer": "https://blog.csdn.net/tansty_zh"
    }
    try:
        html = requests.get(url=title_url, headers=head).text
        page = parsel.Selector(html)
        # 创建解释器
        title = page.css(".title-article::text").get()
        if not title:
            print("未获取到文章标题，可能页面结构发生变化。")
            return
        # 去除文件名中的非法字符
        valid_title = re.sub(r'[\\/*?:"<>|]', '', title)

        content = page.css("article").get()
        if not content:
            print("未获取到文章内容，可能页面结构发生变化。")
            return
        content = re.sub("<a.*?a>", "", content)
        content = re.sub("<br>", "", content)
        content = re.sub("&lt;", "<", content)
        content = re.sub("&gt;", ">", content)
        text = tomd.Tomd(content).markdown

        # 获取当前的目录路径
        path = os.getcwd()
        file_name = "csdn_passage"
        final_road = os.path.join(path, file_name)

        # 检查并创建目录
        if not os.path.exists(final_road):
            os.makedirs(final_road)
            print('目录创建成功！')
        else:
            print('目录已存在。')

        # 构建 Markdown 文件路径
        # md_file_path = os.path.join(final_road, f"{valid_title}.md")
        # with open(md_file_path, mode="w", encoding="utf-8") as f:
        #     f.write(f"#{title}\n")
        #     f.write(text)
        # print(f"文章 {title} 保存为 Markdown 文件成功！")

        # 构建 HTML 文件路径
        html_file_path = os.path.join(final_road, f"{valid_title}.html")
        with open(html_file_path, mode="w", encoding="utf-8") as f:
            # 写入 HTML 文件的基本结构
            f.write("<!DOCTYPE html>\n")
            f.write("<html lang=\"zh-CN\">\n")
            f.write("<head>\n")
            f.write(f"<meta charset=\"UTF-8\">\n")
            f.write(f"<title>{title}</title>\n")
            f.write("</head>\n")
            f.write("<body>\n")
            f.write(f"<h1>{title}</h1>\n")
            f.write(content)
            f.write("</body>\n")
            f.write("</html>")
        print(f"文章 {title} 保存为 HTML 文件成功！")
    except requests.RequestException as e:
        print(f"请求出错：{e}")
    except Exception as e:
        print(f"发生未知错误：{e}")


def main():
    print("本项目由yzq魔改")
    # url = input("请输入网址：")
    url = ""
    spider_csdn(url)


if __name__ == '__main__':
    main()