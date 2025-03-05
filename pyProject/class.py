import uuid
from abc import ABC, abstractmethod

class Equipment(ABC):
    total_count = 0

    def __init__(self, name, power):
        """装备抽象基类"""
        self.name = name
        self.power = power
        # self.equip_id = str(uuid.uuid4[:8]) # 唯一装备编号
        self.equip_id = uuid.uuid4().hex[:8]
        Equipment.total_count += 1
    
    @abstractmethod
    def effect_description(self):
        """装备描述"""
        pass

    @property
    def power(self):
        return self._power
    
    @power.setter
    def power(self, value):
        if value < 0:
            raise ValueError("Power cannot be negative")
        self._power = value

class Weapon(Equipment):
    def __init__(self, name, power, durability = 100):
        super().__init__(name, power)
        self.durability = durability

    def effect_description(self):
        return f"攻击力 + {self.power} 耐久度: {self.durability}"
        
class Weapon(Equipment):
    """武器之类"""
    def __init__(self, name, power, durability = 100):
        super().__init__(name, power)
        self.durability = durability

    def effect_description(self):
        return f"攻击力 + {self.power} 耐久度: {self.durability}"
        
class Armor(Equipment):
    """防具子类（继承）"""
    def __init__(self, name, power, element = None):
        super().__init__(name, power)
        self.element = element

    def effect_description(self):
        elem_info = f"{self.element}属性 " if self.element else " "
        return f"防御力 + {self.power} {elem_info}属性"
    
class GameCharacter:
    """游戏角色类（组合+封装）"""
    character_created = 0 

    def __init__(self, name, job):
        self.name = name
        self.job = job
        self.__health = 100
        self.equipments = []
        GameCharacter.character_created += 1

    def equip(self, equipment):
        if (len(self.equipments) >= 4):
            print("装备已经满了")
            return
        self.equipments.append(equipment)
        print(f"{self.name}装备了{equipment.name}")

    def show_status(self):
        print(f"【{self.name}】 {self.job}")
        print(f"生命值：{self.__health}")
        print("装备列表：")
        for eq in self.equipments:
            print(f" - {eq.name}: {eq.effect_description()}")

    def take_damage(self, damage):
        self.__health = max(0, self.__health - damage)
        print(f"{self.name}受到{damage} 点伤害！剩余生命：{self.__health}")

class Warrior(GameCharacter):
    def __init__(self, name, job):
        super().__init__(name, "战士")
        self.__range = 0 # 愤怒值

    def attack(self):
        attack_power = 15 + sum(eq.power for eq in self.equipments if isinstance(eq, Weapon))
        self.__range = min(100, self.__range + 10)
        return attack_power * (1 + self.__range / 200)
    
class Mage(GameCharacter):
    """法师之类"""
    def __init__(self, name, job):
        super().__init__(name, job)
        self.__mana = 100 #法力值

    def attack(self):
        mana_cost = 20
        if self.__mana < mana_cost:
            print("法力不足！")
            return 0
        self.__mana -= mana_cost
        spell_power = 10 + sum(eq.power for eq in self.equipments if isinstance(eq, Weapon))
        return spell_power * 1.5
    

if __name__ == "__main__":
    # 创建装备
    sword = Weapon("火焰剑", 25, 80)
    shield = Armor("钢盾", 15, "土")
    staff = Weapon("魔法杖", 18)
    robe = Armor("法袍", 10, "水")
    
    # 创建角色
    arthur = Warrior("亚瑟", "战士")
    merlin = Mage("梅林", "法师")
    
    # 装备管理
    arthur.equip(sword)
    arthur.equip(shield)
    merlin.equip(staff)
    merlin.equip(robe)
    
    # 状态显示
    arthur.show_status()
    merlin.show_status()
    
    # 战斗模拟
    dmg_from_arthur = arthur.attack()
    merlin.take_damage(int(dmg_from_arthur))
    
    dmg_from_merlin = merlin.attack()
    arthur.take_damage(int(dmg_from_merlin))
    
    # 统计信息
    print(f"\n已创建角色数量：{GameCharacter.character_created}")
    print(f"总装备数量：{Equipment.total_count}")