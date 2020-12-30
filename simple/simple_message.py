# -*- coding: utf-8 -*-
import requests
import json
import sys
import os.path

sys.path.append('../')

from auth import auth
import config


if __name__ == '__main__':
    data = {
        'message': {
            'to': '01066896321',
            'from': '01042149072',
            'text': '테스트 메시지'
        }
    }
    res = requests.post(config.getUrl('/messages/v4/send'), headers=auth.get_headers(config.apiKey, config.apiSecret), json=data)
    print(json.dumps(json.loads(res.text), indent=2, ensure_ascii=False))
