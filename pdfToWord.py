import sys
from pdf2docx import Converter


def pdf2word(pdf_path):
    try:
        docx_path = pdf_path.replace('.pdf', '.docx')
        cv = Converter(pdf_path)
        cv.convert(docx_path, start=0, end=None)
        cv.close()
        print("\"" + docx_path + "\"", end='')
    except Exception as err:
        print('0', end='')


if __name__ == '__main__':
    pdf_path = sys.argv[1]
    pdf2word(pdf_path)



