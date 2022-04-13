def main():
    file_name = input("File name? ")
    print(media_type(file_name.lower().rstrip(" ")))

def media_type(file_name):
    index_dot = file_name.find(".")
    end = file_name[index_dot+1:]

    if end == "gif":
        return "image/gif"
    elif end == "jpg" or end == "jpeg":
        return "image/jpeg"
    elif end == "png":
        return "image/png"
    elif end == "pdf":
        return "application/pdf"
    elif end == "txt":
        return "text/plain"
    elif end == "zip":
        return "application/zip"
    else:
        return "application/octet-stream"

main()