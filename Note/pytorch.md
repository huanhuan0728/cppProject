## 数据集的拼接

    ```bash
    # 接收两个参数
    from torch.utils.data import ConcatDataset
    train_dataset = ConcatDataset([ants_dataset,bees_dataset])

    ```
