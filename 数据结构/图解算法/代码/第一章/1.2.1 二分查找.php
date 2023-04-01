<?php
/**
 * 二分法查找指定的数组下表
 *
 * @param int $target 目标值
 * @param array $list 列表
 * @return false|float|null
 * @author 陈维锐
 * @date 2023/02/02 18:54
 */
function binary_search($target, $list) {
    $low = 0;
    $high = count($list)-1;

    while($low <= $high) {
        $mid = floor(($low + $high)/2);
        $current = $list[$mid];
        if ($target == $current) {
            return $mid;
        }else if ($target > $current) { // 猜的数字小了
            $low = $mid+1;
        } else { // 猜的数字大了
            $high = $mid-1;
        }
    }

    return null;
}